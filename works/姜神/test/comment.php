<?php
$data = json_decode(file_get_contents('comment.json'), true);
// var_dump($data);
// var_dump($_POST);

// $_GET  $_POST
if($_SERVER['REQUEST_METHOD'] === 'POST' && $_POST['name'] !== '' && $_POST['text'] !== '')  {
// if(isset($_POST['name']) && isset($_POST['text']) && $_POST['name'] !== '' && $_POST['text'] !== '') {
	$current = array('name' => $_POST['name'], 'text' => $_POST['text']);
	array_push($data, $current);
	file_put_contents('comment.json', json_encode($data));
	header('Location: comment.php');
}
?>
<form method="post" action="comment.php">
<input type="text" name="name"><br>
<input type="text" name="text"><br>
<input type="submit">
</form>
<!-- <pre><?php var_dump($_SERVER);?></pre> -->
<?php
for($i = count($data) - 1; $i >= 0; $i--) {
	echo '<p>From '.$data[$i]['name'].'<br>'.$data[$i]['text'].'</p><hr>';
}
?>