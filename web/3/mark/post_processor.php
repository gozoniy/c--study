<?php
if(isset($_POST["firstname"]) && isset($_POST["secondname"]) && isset($_POST["eduform"]) && isset($_POST["comment"]) && isset($_POST["bananas"])) 
{
    $name = htmlentities($_POST["firstname"]);
    $sname = htmlentities($_POST["secondname"]);
    $eduform = htmlentities($_POST["eduform"]);
    $gift_wrap = "нет";
    if(isset($_POST["gift_wrap"])) $gift_wrap = "да";
    $comment = htmlentities($_POST["comment"]);
    $bananas = $_POST["bananas"];
    $output =";

    $str=$name.', '.$sname.', '.$eduform.', '.$gift_wrap.', '.$bananas.', '.$comment.'"\r\n"; 
    $file=fopen('order.txt','r+');
    fputs($file, $str);
    fclose($file);
}

file_put_contents("guestbook.txt", $entry . $old_entries);
    <html>
    <head>
    <title>Данные заказа</title>
    </head>
    <body>
    Вас зовут: $name $sname<br />
    Зона доставки: $eduform<br />
    Обернуть в подарочную обёртку: $gift_wrap<br />
    Выбранные сорта бананов:
    <ul>";
    foreach($bananas as $item)
        $output.="<li>" . htmlentities($item) . "</li>";
    $output.="</ul></body></html>";
    echo $output;
}
else
{   
    echo "Введенные данные некорректны";
}
?>
