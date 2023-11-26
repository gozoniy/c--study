<?php
$db = @ mysqli_connect( 'localhost' , 'root' , '', 'Lab3Web' ) or die ( 'Ошибка соединения с БД');

if (! $db ) die ( mysqli_connect_error());

mysqli_set_charset( $db, "utf8" ) or die ( 'Не установлена кодировка' );
?>