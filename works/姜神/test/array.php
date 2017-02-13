<?php
// JSON
/*
{
	"name": "xxxx",
	"sex": "male",
	"likes": ["A", "B", "C"]
}


[
	{
		"name": "xxxx",
		"sex": "male"
	},
	{
		"name": "yyy",
		"sex": "male"
	}
]
*/
$arr = ["A", "B", "C"];
$arr = Array("A", "B", "C");

$bb = [];
$bb['name'] = 'xxxx';
$bb['sex'] = 'male';
var_dump($bb);
//array(2) { ["name"]=> string(4) "xxxx" ["sex"]=> string(4) "male" }
$cc = Array(
	'name' => 'xxxx',
	'sex' => 'male',
	'sex' => 'male2',
	'sex' => 'male3',
	);
var_dump($cc);

/*
sort - rsort
ksort - krsort (k = key)
asort - arsort
*/