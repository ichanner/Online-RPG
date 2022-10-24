<?php


class DB{

	private static $_instance = null;
	private $_pdo;
	private $_error = false;
	private $_count = 0;
	private $_query;
	private $_result;

	 function __construct($Db){
		

		try{
		
			$this->_pdo = new PDO('mysql:host=' . Config::Get('Mysql/'. $Db .'/host') . ';dbname=' . Config::Get('Mysql/'. $Db .'/db'), Config::Get('Mysql/'. $Db .'/user', Config::Get('Mysql/'. $Db .'/pass')));

		}

		catch(PDOException $e){
		
			die($e->getMessage());
		
		}

				
	}


	public static function GetDBInstance($Db){
	

		if(!isset(self::$_instance)){
		
			self::$_instance = new DB($Db);
		}

		return self::$_instance;
	}



	public function query($sql, $params = array()){

		$this->_error = false;

		if($this->_query = $this->_pdo->prepare($sql)){
		
			

			if(count($params)){
				$pos = 1;
				foreach($params as $param){
					
					$this->_query->bindValue($pos, $param);
					$pos++;
				}
			}

			if($this->_query->execute()){
			
		

				$this->_results = $this->_query->fetchAll(PDO::FETCH_OBJ);
				$this->_count = $this->_query->rowCount();
			

			}
			else{
			
				$this->_error = true;
			}
		}

		return $this;
	
		
	}

	private function action($action, $row, $table, $where = array()){
		
		if(count($where) === 3){
			
			$operators = array('=', '>', '<', '<=', '>=', '!=');

			$field = $where[0];
			$operator = $where[1];
			$value = $where[2];
		
			if(in_array($operator, $operators)){
			
				$sql = "{$action} {$row} FROM {$table} WHERE {$field} {$operator} ?";
			
				if(!$this->query($sql, array($value))->isError()){
				
					return $this;
				
						
				}
				
				
			}
			
		}

		return false;

	}


	public function get($table, $row, $where = array()){
	
		return DB::action("SELECT", $row, $table, $where);
	}

	public function delete($table, $row, $where = array()){
	
		return DB::action("DELETE", $row, $table, $where);
	}


	public function insert($table, $fields = array()){
		
		if(count($fields)	){

		$keys = array_keys($fields);
		$values = '';
		$index = 1;

		foreach($fields as $field){
			
			$values .= '?';

			if($index < count($fields)){
			
				$values .= ', ';
			}
			
			$index++;
		}

		$sql = "INSERT INTO {$table} (`" . implode('`, `', $keys) . "`) VALUES ({$values})";
		//echo $sql;
		if(!$this->query($sql, $fields)->isError()){
		
			return true;

		}

	
	}

	return false;

	}

	public function update($table, $fields, $row, $operator, $id){
		
		if(count($fields)){

			$set = '';
			$index = 0;
			$operators = array('=', '>', '<', '<=', '>=');


			foreach($fields as $name => $value){
			
				$set .= "{$name} = ?";

				if($index < count($fields)-1){
				
					$set .= ', ';
				}
				$index++;
			}
			
			if(in_array($operator, $operators)){
			
				$sql = "UPDATE {$table} SET {$set} WHERE {$row} {$operator} {$id}";
				//echo $sql;
					
				if(!$this->query($sql, $fields)->isError()){
					
					return $this;

				}
				else{
					
				   return false;
				}
			}
				
		}

		

		return false;

	}

	
	public function fetch($obj, $row_name){
	
		foreach ($obj->getResults() as $row){
	
			echo $row->$row_name;
		}
	}


	public function getResults(){
		
		return $this->_results[0];
	}


	public function isError(){
	
		return $this->_error;
	}


	public function count(){
	
		return $this->_count;
	}


}





?>
