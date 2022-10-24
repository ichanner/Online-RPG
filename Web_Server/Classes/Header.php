<?php

class Header{
	


	public function create($string){
	
		header($string);
	}

	public function get($field){
	
		$headers  = getallheaders();
	
		foreach($headers as $key => $value){
		
			if($key == $field){

				return $value;
			}
		
		}
		
	}


	
}



?>