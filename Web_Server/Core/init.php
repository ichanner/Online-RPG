<?php

session_start();
error_reporting(0);



array(

$GLOBALS['namespaces'] = array(


		'Mysql' => array(
	
			'AccountDB' => array(
		
				'host' => 'localhost',
				'user' => 'root',
				'pass' => '',
				'db' => 'backyard_users'
			),


			"UserBulkDB" => array(
			
				'host' => 'localhost',
				'user' => 'root',
				'pass' => '',
				'db' => 'backyard_userblobs'

			),


			'AuthDB' => array(
			
				'host' => 'localhost',
				'user' => 'root',
				'pass' => '',
				'db' => 'backyard_auth'
			)

		),

		'Session' => array(
		
			'sessionName' => 'authSession',
			'expire' => 3600
		),

		'CSRF' => array(
		
			'csrfName' => 'csrfToken',
			'expire' => 3600
		),
		
		'AccessToken' => array(
			
			'type' => "Bearer",
			'expire' => time() + 60,
			'expireTime' => 60
		)

		
	)

);





spl_autoload_register(function($class){

	require_once 'C:/xampp/htdocs/BasementGames/BackYardTales/Classes/' . $class . '.php';
});



require_once 'C:/xampp/htdocs/BasementGames/BackYardTales/Functions/Sanatize.php';





?>