<?php

require_once 'C:/xampp/htdocs/BasementGames/BackYardTales/Core/init.php';


if(isset($_POST["change"])){
	
	$user = new User();
	
	$key = Http::get('recoverykey');
	
	$validate = new Validation();


	$valid = $validate->check($_POST, array(

		"password" => array(

			"Required" => true,
			"Min" => 2,
			"Max" => 20

		)

	));


	if($valid->Passed())

		if($user->recoverAccount(Http::get('password'), $key)){
	
			echo "Successfully Changed!";

			Header::create("HTTP/1.1 201 Success");
		}


		else{
	
			echo "Error updating password";

			Header::create("HTTP/1.1 403 Unauthorized");
		}	

	else
	{
	
		foreach($valid->getErrors() as $error){
		
			echo $error . "</br>";
		}
	}
	
}

?>


<html>


<head>

</head>

<body>


 <center>

 <h1> Change Password </h1>
		
	 <div>

	 <form method="POST">

		<input type="password" placeholder="New Password" name="password"></input> 
		<br/><br/>

		<input type="submit" value="Change" name="change"></input> 


     </form>

	 </center>
		
	 </div>



</body>

</html>