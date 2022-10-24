<?php





require_once 'C:/xampp/htdocs/BasementGames/BackYardTales/Core/init.php';

if(Http::Empty('get')){

	try{

		$Vkey = Http::Get('vkey');

		$vkeyCheck = DB::GetDBInstance("AccountDB")->query("SELECT * FROM `accounts` WHERE Vkey = '{$Vkey}' AND Verified = 0");

		if($vkeyCheck->count()){

			if(DB::GetDBInstance("AccountDB")->update("accounts", array( "Verified" => 1), "`Vkey`", "=", "'{$Vkey}'")){
		
				echo "Verified";

				header("HTTP/1.1 201 Account Verified");
			}

			else{
			
				echo "An error has occured";
				
				header("HTTP/1.1 500 Server Error");
			}
		}

		else{
	
			echo "Invalid key";

			header("HTTP/1.1 405 Invalid Key");
		}

	}

	catch(Exception $e){
		
		die($e->getMessage());
	}

}






?>