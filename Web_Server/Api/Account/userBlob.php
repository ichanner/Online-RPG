<?php


require_once 'C:/xampp/htdocs/BasementGames/BackYardTales/Core/init.php';

if(Http::Empty('post')){

	$usersBulk = array();

	$platform = Http::Get('platformId');
	
	$mysqli = new mysqli("localhost", "root", "", "backyard_userblobs");

	$fetch = $mysqli->query("SELECT * FROM `" . $platform . "`");

	while($row = mysqli_fetch_assoc($fetch)){
	
		$usersBulk[] = $row;
	}

	echo '{"accounts":' . json_encode($usersBulk) . '}';

}

	
?>