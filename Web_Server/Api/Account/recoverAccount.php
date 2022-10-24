<?php
ob_start();
require_once 'C:/xampp/htdocs/BasementGames/BackYardTales/Core/init.php';


if(Http::Empty('post')){


	$validate = new Validation();

	$email = Http::get('Email');


	$valid = $validate->check($_POST, array(

		"Email" => array(

			"Required" => true,
			"Email" => true
		)

	));


	if($valid->Passed()){

		$user = new User();
		$key = $user->forgotAccount($email);

		if($key != NULL){

			new Mail($email, "Forgotten Password",  "<a href='http://localhost/BasementGames/BackYardTales/ChangePassword?recoverykey=$key'> Change Password </a>" );
			
			Header::create("HTTP/1.1 202 Authorized");
		}
	}

	else{
		
		ob_end_clean();
		
		echo '{"errors":' . json_encode($valid->getJsonErrors()) . '}';

		Header::create("HTTP/1.1 400 Error");
	}

}

?>

		