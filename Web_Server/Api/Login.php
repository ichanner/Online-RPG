
<?php
ob_start();
require_once 'C:/xampp/htdocs/BasementGames/BackYardTales/Core/init.php';

if(Http::Empty('post')){

	
	$user = new User();
	$validate = new Validation();


	$valid = $validate->check($_POST, 
	
	array(
	
		"Username" => array(
		
			"Required" => true
		),

		"Password" => array(
		
			"Required" => true
		)

	));


	if($valid->Passed()){
	
		ob_end_clean();

		if($user->Login(Http::Get("Username"), Http::Get("Password"), Http::Get("platformId"), Http::Get("remember"))){
			

			header("HTTP/1.1 202 Logged in");

		}

		else{
		
			header("HTTP/1.1 401 Wrong Username Or Password");
		}

	}

	else{
		
		ob_end_clean();
		echo '{"errors":' . json_encode($valid->getJsonErrors()) . '}';
		
		header("HTTP/1.1 400 Error Creating Account");
	}
}








?>