<?php


use Firebase\JWT\JWT;

require_once'C:/xampp/htdocs/BasementGames/BackYardTales/vendor/autoload.php';
require_once 'C:/xampp/htdocs/BasementGames/BackYardTales/vendor/firebase/php-jwt/src/JWT.php'; 


class Token{


	public function createRefreshToken($id){
			
			
			$RefreshPayload = [
				
				"iat" => time(),
				"iss" => Config::get("Mysql/AccountDB/host"),
				"userId" => $id
			];

			$jwtRefreshToken = JWT::encode($RefreshPayload, getenv(REFRESH_KEY));

			$encodedToken = base64_encode($jwtRefreshToken);

			Token::Add($encodedToken);

			$accessToken = Token::createAccessToken($encodedToken, true);
				
			echo json_encode(array("refreshToken" => $encodedToken, "accessToken" => $accessToken, "tokenType" => Config::get("AccessToken/type"), "expiresIn" => Config::get("AccessToken/expireTime")));

	}


	public function createAccessToken($refreshToken, $login = false){
	
		
			$decodedToken = JWT::decode(base64_decode($refreshToken), getenv(REFRESH_KEY), array('HS256'));

			$AccessPayload = [
				
				"iat" => time(),
				"iss" => Config::get("Mysql/AccountDB/host"),
				"exp" => Config::get("AccessToken/expire"),
				"userId" =>	$decodedToken->userId,
			];		

			
			$jwtToken = JWT::encode($AccessPayload, getenv(ACCESS_KEY));

			
			if($login){
			
				return $jwtToken;
			}
			else{
			
				echo json_encode(array("accessToken" => $jwtToken, "tokenType" => Config::get("AccessToken/type"), "expiresIn" => Config::get("AccessToken/expireTime")));
			}
	}



	public function deleteRefreshToken($token){

		Token::Delete($token);
	}


	public function authenticateToken($header){
		
		
		if($header != null){

		
			$token = Token::getBearerToken($header);

			$decodedToken = JWT::decode($token, getenv(ACCESS_KEY), array('HS256'));
			
			return $decodedToken->userId;

		}

		return NULL;
		
	}

	
	public function verifyRefreshToken($token){
	
		$token_check = DB::GetDBInstance("AccountDB")->get("tokens", "*", array("Token", "=", "{$token}"));

		if($token_check->count()){

			return true;
		}
		
		return false;
	}


	public function is_Expired($header){
	
		try{

			JWT::decode(Token::getBearerToken($header), getenv(ACCESS_KEY), array('HS256'));
		}

		catch(\Firebase\JWT\ExpiredException $e){

			return true;
		}
		
		return false;
		
	}


	private function Add($token){
	
		DB::GetDBInstance("AccountDB")->insert("tokens", array(
		
			"Token" => $token
		
		));
	}


	private function Delete($token){
	
		DB::GetDBInstance("AccountDB")->delete("tokens", "*", array(
		
			"Token", "=", "{$token}"
		
		));
	}

	private function getBearerToken($header){
	
		if (preg_match('/Bearer\s(\S+)/', $header, $authHeader)) {
			
			return $authHeader[1];
		}

	}


}


?>






















