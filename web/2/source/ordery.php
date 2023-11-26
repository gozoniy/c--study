<?php
if(isset($_POST["user"]) && isset($_POST["email"]) && isset($_POST["phone"]) && isset($_POST["comment"]) && isset($_POST["company"])) 
{
    $name = htmlentities($_POST["User"]);
    $mail = htmlentities($_POST["email"]);
    $phone = htmlentities($_POST["phone"]);
    $loader = "нет";
    if(isset($_POST["loader"])) $loader = "да";
    $comment = htmlentities($_POST["comment"]);
    $company = $_POST["company"];
    $output =";
    $str = $name . ', ' . $mail . ', ' . $loader . ', ' . $phone . ', ' . $company . ', ' . $comment .;
    $file=fopen('order.txt','r+');
    fputs($file, $str);
    fclose($file);
}

file_put_contents('order.txt', $entry . $old_entries);
    <html>
    <head>
    <title>Форма отправки для связи</title>
    </head>
    <body>
    <br />Ваше имя: $name<br />
    Ваш e-mail: $mail<br />
    Ваш номер телефона: $phone<br />
    Потребуются грузчики: $loader<br />
    Транспортная компания:
    <ul>";
    foreach($company as $item)
        $output.="<li>" . htmlentities($item) . "</li>";
    $output.="</ul></body></html>";
    echo $output;
}
else
{   
    echo "Проверьте вашу форму.";
}
?>
