<?php

class Mail{


	public function __construct($to, $sub, $msg, $from = "ianwchanner@gmail.com"){
		

		$headers = "From: ". $from ." \r\n";
		$headers .= "MIME-Version: 1.0" . "\r\n";
		$headers .= "Content-type:text/html;charset:UTF-8" . "\r\n";

		mail($to,$sub,$msg,$headers);

	}

}



?>