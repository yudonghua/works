<?php
// $str1 = 's\nds';
// $str2 = "s\nds$str1";
// $str3 = 's'."\n".'ds'.$str1;
$str2 = [];
$str2['text'] = $_POST['text'];
file_put_contents('test', json_encode($str2));
$str = json_decode(file_get_contents('test'), true);
// var_dump(json_decode(file_get_contents('test'), true));
// var_dump(json_decode(file_get_contents('test'), false));
?>
<form method="post" action="file.php">
	<textarea name="text"><?php echo $str['text'];?></textarea>
	<input type="submit">
</form>
