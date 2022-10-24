<?php

class Hash{


	public function make($string, $salt= ''){

		return password_hash($string.$salt, PASSWORD_BCRYPT, ["cost" => 15]);
	
	}

	public function salt($len){

		$salt = random_bytes($len);
		return base64_encode(bin2hex($salt));
	}	


	public function random($string){
	
		return md5($string . time().rand());
	}


}


?>