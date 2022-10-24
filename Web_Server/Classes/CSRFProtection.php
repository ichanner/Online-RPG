<?php

class CSRFProtection{
	
	
	public function create(){
	
		return $_SESSION['name'] = Hash::salt(32);
	}

	   

	public function checkCSRF($key){
	
		if(Session::exists(Config::get("CSRF/csrfToken")) && $key === Session::get(Config::get("CSRF/csrfToken"))){

			Session::delete(Config::get("CSRF/csrfToken"));
			return true;

		}

		return false;
		
	}	

}

?>