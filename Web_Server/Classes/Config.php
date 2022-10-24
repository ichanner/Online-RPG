
<?php

class Config{


	public static function Get($path = null){
	
		if($path){


			$ready = false;		
			$config = $GLOBALS['namespaces'];
			$path = explode('/', $path);

			foreach($path as $bit){
			
				if(isset($config[$bit])){
				
					$config = $config[$bit];
					$ready = true;
					
				}
				else{
				
					$ready = false;
				}
			}

			//if($ready){
				
				return $config;
			//}

		}

		return false;
	}

}


?>