<?php

class accountBulk{


	public function addToBulk($platformId, $id){
		
		$db = new DB("UserBulkDB");
		
		$idCheck = $db->get($platformId, "*", array("userId", "=", $id));

		$user = new User($id);

		if($idCheck->count() == 0){
			
			$db->insert($platformId, array(
	
				"userId" => $id,
				"username" => $user->getUsername(),
				"nickname" => $user->getNickname(),
				"rank" => $user->getRank(),
				"avatar" => $user->getAvatar(),	
				"platforms" => $user->getPlatforms(),
				"joined" => $user->getJoined()
			));
		}
	}


	public function createBulk($platformId){

		$db = new DB("UserBulkDB");
		
		$db->query('CREATE TABLE `backyard_userblobs`.`' . $platformId . '` ( `id` INT(11) NOT NULL AUTO_INCREMENT ,  `userId` INT NOT NULL ,  `username` TEXT NOT NULL ,  `nickname` TEXT NOT NULL ,  `rank` INT NOT NULL ,  `avatar` TEXT NOT NULL ,  `platforms` INT NOT NULL ,  `joined` TIMESTAMP NOT NULL ,    PRIMARY KEY  (`id`)) ENGINE = InnoDB;');
		
	}

}


?>