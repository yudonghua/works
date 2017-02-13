<?php
// comment
/*
comment
fd
*/
$str = 'hello world';
// echo '<h1>'.$str.'</h1>', 'a';
// print $str;

$arr = ["A", "ABC"];

var_dump($str);
echo '<br>';
print_r($str);

$arr = 1;

echo '<br>';
var_dump($arr);
echo '<br>';
print_r($arr);


function A($num, $str, $i) {
	return $num.$str.$i;
}
echo '<br>'.A(123, 'a');

if ($str === 'a') {
}
else {
}

switch ($str) {
	case 'a':
		# code...
		break;
	
	case 'b':
		# code...
		break;
	
	default:
		# code...
		break;
}

while() {

}

for($i = 0; $i < 10; $i++) {
}