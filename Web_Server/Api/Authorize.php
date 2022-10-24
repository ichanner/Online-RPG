<?php

require_once 'C:/xampp/htdocs/BasementGames/BackYardTales/Core/init.php';

$refreshToken = Http::Get('refreshToken');
$accessToken = Header::get('authorization');

if(Token::is_Expired($accessToken)){
	
	Header::create("HTTP/1.1 201 Granted");

	if(Token::verifyRefreshToken($refreshToken)){
							
		Token::createAccessToken($refreshToken);			
	}
	else{

		Header::create("HTTP/1.1 403 Unauthorized");
	}
}









?>