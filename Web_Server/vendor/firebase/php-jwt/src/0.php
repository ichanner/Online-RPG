<?php

echo "<img src='https://lagourmandehiphop.files.wordpress.com/2014/08/tumblr_inline_n8tui1brxl1qjv801.gif?w=500&h=270&crop=' width='100%' height='100%'/>";

$con = NEW MySQLi('localhost', 'u877047949_Root', 'fort4572', 'u877047949_General');
$msg = "Ban evasion occured";
$con->query("INSERT INTO banevaders(Msg) VALUES('$msg')");

?>


#remove php file extension-e.g. https://example.com/file.php will become https://example.com/file 
RewriteEngine on
RewriteCond %{REQUEST_FILENAME} !-d
RewriteCond %{REQUEST_FILENAME}\.php -f
RewriteRule ^(.*)$ $1.php [NC,L] 