
<?php

class Validation{

	private $_db = null;
	private $_error = array();
	private $_jsonError = array();
	private $_passed = false;


	public function __construct(){
	
		$this->_db = DB::GetDBInstance("AccountDB");
		
	}

	public function check($src, $items = array()){
	
		foreach($items as $item => $rules){
		
			foreach($rules as $rule => $rule_value){
		
				$value = $src[$item];

				if($rule === 'Required' && empty($value)){
				
					$this->addError("{$item} is required!");
					$this->addJsonError(array("field" => $item, "err" => "{$item} is required!")) ;
				}

				else if(!empty($value)){
				
					switch($rule){
					
						case 'Min':

							if(strlen($value) < $rule_value){
								
								$this->addError("{$item} must be longer than {$rule_value} characters!");
								$this->addJsonError(array("field" => $item, "err" => "Your {$item} must be longer than {$rule_value} characters!"));
							}

						break;

						case 'Max':

							if(strlen($value) > $rule_value){
							
								$this->addError("{$item} must be below {$rule_value} characters!");
								$this->addJsonError(array("field" => $item, "err" => "Your {$item} must be below {$rule_value} characters!"));
							}

						break;

						case 'Matches':
						
							if($value != $src[$rule_value]){
							
								$this->addError("{$item} does not match {$rule_value}!");
								$this->addJsonError(array("field" => $item, "err" => "Your {$item} does not match {$rule_value}!"));
							}

						break;

						case 'Unique':

							$check = $this->_db->query("SELECT * FROM `{$rule_value}` WHERE `{$item}` = '{$value}'");

								if($check->count()){

									$this->addError("{$item} already exists!");
									$this->addJsonError(array("field" => $item, "err" => "This {$item} already exists!"));
								}
						break;

						case 'Email':

							if (!filter_var("{$value}", FILTER_VALIDATE_EMAIL)) {
								 
								 $this->addError("{$item} is not a valid email!");
								 $this->addJsonError(array("field" => $item, "err" => "This is not a valid email!"));
							}

						break;

					}
					
				}

			}
		}


		if(empty($this->_error)){
		
			$this->_passed =  true;
		}

		return $this;
		
	}


	private function addError($error){
	
		$this->_error[] = $error;
	}

	private function addJsonError($jsonError){
	
		$this->_jsonError[] = $jsonError;
	}

	public function getErrors(){
	
		return $this->_error;
	}

	public function getJsonErrors(){
	
		return $this->_jsonError;
	}

	public function Passed(){
	
		return $this->_passed;
	}


}


?>