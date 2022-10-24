<?php



class Cookie{


public function exists($name){

	if(isset($_COOKIE[$name])){
		
		return true;
	}
	return false;
}

public function create($name, $value, $expire, $path = '/', $httpOnly = false){

	setcookie($name, $value, $expire, $path, null, null, $httpOnly);
}


public function delete($name){

	if(Cookie::exists($name)){
		
		unset($_COOKIE[$name]);
		setcookie($name, null, -1, '/');
	}
	return false;
}

public function get($name){

	if(Cookie::exists($name)){
		
		return $_COOKIE[$name];
	}
	return NULL;
}


}