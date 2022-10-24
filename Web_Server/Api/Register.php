


<?php

ob_start();

require_once 'C:/xampp/htdocs/BasementGames/BackYardTales/Core/init.php';



if(Http::Empty('post')){


	if(strlen(Http::get("Email")) == 0){
		
		$emailDb = "";
		$isEmail = false;
		$Email = NULL;
	}

	else{
		
		$emailDb = "accounts";
		$isEmail = true;
		$Email = Http::Get('Email');
	}
	
	$validate = new Validation();

	$valid = $validate->check($_POST, array(

		"Username" => array(

			"Required" => true,
			"Min" => 2,
			"Max" => 20,
			"Unique" => "accounts"
		
		),

		"Password" => array(

			"Required" => true,
			"Min" => 2,
			"Max" => 20

		),

		"Confirmation" => array(

			"Required" => true,
			"Matches" => 'Password'
	
		),

		"Email" => array(

			"Unique" => $emailDb,
			"Email" => $isEmail
		)

	));

	if($valid->Passed()){
	
			$user = new User();
			$platformId = Http::Get('platformId');
			$Avatar = "Default.jfif"; 
			$Salt = Hash::salt(10);
			$Name = Http::Get('Username');
			$Hash = Hash::make(Http::Get("Password"), $Salt);
			$Vkey =  Hash::random($Name);
		
		try{
			
		
			if($user->create(array(

				'Username' => $Name,

				'Nickname' => $Name,

				'Avatar' => $Avatar,	

				'Vkey' => $Vkey,

				'Hash' => $Hash,

				'Salt' => $Salt,

				'Email' => $Email,

				'Rank' => 1,

				'Verified' => 0,

				'recoveryKey' => NULL,

				'Platforms' => 1

			), $platformId)){
				
				if($isEmail){
					
					new Mail($Email, "Verification",  "<a href='http://localhost/BasementGames/BackYardTales/Verify?vkey=$Vkey'> Verify Your Account </a>" );
				}

				ob_end_clean();

				header("HTTP/1.1 201 Account Created");

				$user->Login(Http::get("Username"), Http::get("Password"), Http::Get('platformId'), true);

				
				
			}

		}

		catch(Exception $e){
		
			die($e->getMessage());
		}
		
	}
	else{

		ob_end_clean();
		echo '{"errors":' . json_encode($valid->getJsonErrors()) . '}';
		
		header("HTTP/1.1 400 Error Creating Account");

	}


}



?><!DOCTYPE html>
<html>
  <head>
  </head>
  <link href="https://cdnjs.cloudflare.com/ajax/libs/video.js/7.1.0/video-js.css" rel="stylesheet">
  <script src="https://cdnjs.cloudflare.com/ajax/libs/video.js/7.1.0/video.js">
  </script>
  <video  muted id="player" res='1080' src="https://vjs.zencdn.net/v/oceans.mp4" class="video-js" controls preload="auto" width="640" height="264"  data-setup='{ "controls": true, "autoplay": false, "preload": "auto" }'>
    <source id="mp4" src="https://vjs.zencdn.net/v/oceans.mp4" type='video/mp4'>
  </video>
</html>

<?php

error_reporting(0);
include ("vendor/autoload.php");

use ElephantIO\Client;
use ElephantIO\Engine\SocketIO\Version2X;

session_start();

$queues = array();


function getVideos($room){

  $conn = mysqli_connect("localhost", "root", "", "watchstuff");
  
  $sql = $conn->query("SELECT * FROM queues WHERE Room = '$room'");
  
  while($row = $sql->fetch_all(MYSQLI_ASSOC)){

    return $row;
  }
}

function vote($downVote, $videoId){

  $conn = mysqli_connect("localhost", "root", "", "watchstuff");
  $sql = '';

  if($conn){

    if($downVote){

        $sql = "UPDATE queues SET 'no'={$voteNumber} WHERE 'VideoId' = '".$VideoId."'";
    
    }
    else{

        $sql = "UPDATE queues SET 'yes'={$voteNumber} WHERE 'VideoId' = '".$VideoId."'";
    
    }

    mysqli_query($conn, $sql);
    $conn->close();
  }
}

function addVideo($video, $videoId, $requestedId, $room){
  
  $conn = mysqli_connect("localhost", "root", "", "watchstuff");

  if($conn){
    
    $yes = 0;
    $no = 0;

    $sql = "INSERT INTO queues(Video,VideoId,RequestedId,Yes,No,Room) VALUES('".$video."', '".$videoId."', '".$requestedId."', '".$room."')";

    mysqli_query($conn, $sql);
    $conn->close();
  }   
}


$_SESSION['id'] = uniqid();

if ($_SESSION['room'] != $_GET['room'])
{

    unset($_SESSION['owner']);
}
else
{
    $_SESSION['owner'] = true;
}

$url = '';
$owner = $_SESSION['owner'];
$currentRoom = $_GET['room'];
$id = $_SESSION['id'];

$version = new Version2X("localhost:3001");
$client = new Client($version);
$client->initialize();

getVideos($currentRoom);


if (isset($_POST["uploadfile"]))
{

    $video = $_FILES['file']['tmp_name'];
    $videoName = $_FILES['file']['name'];
    $videoSize = $_FILES['file']['size'];
    $fileExt = explode('.', $videoName);
    $fileRealExt = strtolower(end($fileExt));

    $allowed = array(
        'mp4',
        'webm',
        'mov',
        'ogv'
    );

    if (in_array($fileRealExt, $allowed))
    {

        if ($vieoSize < 1000000)
        {

            $newName = uniqid('', true) . "." . $fileRealExt;
            $tar = "videos/" . $newName;

            if (move_uploaded_file($_FILES['file']['tmp_name'], $tar))
            {

            }
            else
            {
                echo "Error uploading video";
            }

            $url = "https://coachsfinest.com/Streaming/videos/" . $newName;

            if($owner){

                ?>
                    <script>
                        document.getElementById("mp4").setAttribute("src", <?php echo json_encode($url) ?>);
                    </script>

                <?php

              $client->emit("changeVideo", array(
                  "Video" => $url,
                  "Room" => $currentRoom
              ));
            }
            else{

              $videoId = bin2hex(random_bytes(32));

              $client->emit("addQueue", array(
                  "Video" => $url,
                  "VideoId" => $videoId,
                  "RequestedId" => $id,
                  "Room" => $currentRoom
              ));

              addVideo($url, $videoId, $id, $currentRoom);
            }

        }
        else
        {

            echo "Video can not be over 100mb!";
        }
    }
    else
    {

        echo "Video format is not supported!";
    }
}

if (isset($_POST['submit']))
{

    $url = $_POST['url'];

    ?>

        <script>
            document.getElementById("mp4").setAttribute("src", <?php echo json_encode($url) ?>);
        </script>

    <?php

    if($owner){

      $client->emit("changeVideo", array(
        "Video" => $url,
        "Room" => $currentRoom
      ));
    }
    else{

        $videoId = bin2hex(random_bytes(32));

        $client->emit("addQueue", array(
          "Video" => $url,
          "VideoId" => $videoId,
          "RequestedId" => $id,
          "Room" => $currentRoom
        ));

        addVideo($url, $videoId, $id, $currentRoom);
    }

}



?>


