

<?php


class Session{


public function exists($name){
	

	if(isset($_SESSION[$name])){
	
		return true;
	}
	return false;

}

public function put($name, $value){

	$_SESSION[$name] = $value;
}

public function get($name){

	return $_SESSION[$name];
}


public function destroy($name){

	if(Session::exists($name)){
		
		unset($_SESSION[$name]);
	}
}



}


?>