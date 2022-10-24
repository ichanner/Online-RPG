<?php
ob_start();
require_once 'C:/xampp/htdocs/BasementGames/BackYardTales/Core/init.php';

if(Http::Empty('post')){

	$platformId = Http::Get('platformId');
	$id = Http::Get('id');

	if(User::platformAuthCheck($id, $platformId)){
	
		ob_end_clean();

		Token::createRefreshToken($id);	

		Header::create("HTTP/1.1 202 Authorized");
	}

	else{
	
		Header::create("HTTP/1.1 403 Unauthorized");
	}
}


?>