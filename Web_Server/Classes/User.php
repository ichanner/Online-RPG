<?php


class User{
	

	private $_db;
	private $_user;
	private $_data;
	private $_id;

	public function getId(){return $this->_id;}
	public function getUsername(){return $this->_user->getResults()->Username;}
	public function getNickname(){return $this->_user->getResults()->Nickname;}
	public function getRank(){return $this->_user->getResults()->Rank;}
	public function getAvatar(){return $this->_user->getResults()->Avatar;}
	public function getEmail(){return $this->_user->getResults()->Email;}
	public function getHash(){return $this->_user->getResults()->Hash;}
	public function getSalt(){return $this->_user->getResults()->Salt;}
	public function getPlatforms(){return $this->_user->getResults()->Platforms;}
	public function getJoined(){return $this->_user->getResults()->Joined;}
	public function data(){return $this->_data;}

	public function __construct($id = null){
		
		$this->_id = $id;
		$this->_db = DB::GetDBInstance("AccountDB");	
		$this->_user = $this->_db->get("accounts", "*", array('Id', '=', $id));

	}


	public function create($fields = array(), $platformId = null){

	
		if($this->_db->insert("accounts", $fields)){
			
			accountBulk::createBulk($platformId);

			return true;
		}


		return false;
	}


	public function find($username = null){
	
		$user = $this->_db->get("accounts", "*", array('Username', '=', $username));
		
		if($user->count()){

			$this->_data = $user->getResults();
			
			return true;
			
		}

		return false;		
	}



	public function logOut(){
				
		Token::deleteRefreshToken();
	}

		
	public function Login($username, $password, $platformId, $remember){
	
		$user = $this->find($username);

		if($user){

			if(password_verify($password . $this->data()->Salt, $this->data()->Hash)){
				
				$id = $this->data()->Id;
				
				if($remember){
				
					accountBulk::addToBulk($platformId, $id);
				}
				
				Token::createRefreshToken($id);	
			
				return true;
			}

			return false;
			
		}

		return false;	
	}


	function platformAuthCheck($id, $platformId){
	
		$db = new DB("UserBulkDB");

		$platformCheck = $db->get($platformId, "*", array("userId", "=", $id));

		if($platformCheck > 0){
			
			return true;
		}

		return false;
	}


	function forgotAccount($email){
		
		$key = Hash::random($email);

		if($this->_db->update("accounts", array("recoveryKey" => $key), "`Email`", "=", "'{$email}'")){
			
			return $key;
		}
		
		return NULL;
	}


	function recoverAccount($plainText, $key){
		
		$Salt = Hash::salt(10);
		$newPassword = Hash::make($plainText, $Salt);

		$keyCheck = $this->_db->get("accounts", "*", array("recoveryKey", "=", "{$key}"));

		if($keyCheck->getResults()->recoveryKey != NULL){

			if($this->_db->update("accounts", array("Hash" => $newPassword, "Salt" => $Salt), "`recoveryKey`", "=", "'{$key}'")){
			
				$this->_db->update("accounts", array("recoveryKey" => NULL), "`recoveryKey`", "=", "'{$key}'");

				return true;
			}
		}
		
		return false;
	}

}



?>