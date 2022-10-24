
<?php

class Http{

	
	public function Empty($method = 'post'){
		
		switch ($method) {
	case 'post':
		return (!empty($_POST) ? true : false);
		break;
	
	case 'get':

	return (!empty($_GET) ? true : false);

	default:
		return false;
		break;
}
	}


	public function Get($value){
		

		if(isset($_POST[$value])){
		
		return($_POST[$value]);

		}
		else if(isset($_GET[$value])){
		
			return($_GET[$value]);
		}

	}



	public function setStatus($status, $msg = ''){
	
		header("HTTP/1.1". $status . $msg);
	}





}