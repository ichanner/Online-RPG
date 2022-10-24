<?php
	ob_start();
	require_once 'C:/xampp/htdocs/BasementGames/BackYardTales/Core/init.php';

	$user = new User(Http::Get("Id"));

	ob_end_clean();

	echo json_encode(array("Id" => $user->getId(), "Username" => $user->getUsername()));
	
?>
