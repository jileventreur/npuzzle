<?php
	
	$loop = 35;
	$i = 0;
	$PATH = ".";
	$gen = "gen.py";
	$prog = "a.out";
	$options = " -si10000 ";
	$dim = "4";
	$output;
	$puzzle = array();
	while ($i <= $loop)
	{
		exec($PATH . "/" . $gen . $options . $dim . " > test.pz");
		exec($PATH . "/" . $prog . " test.pz", $output);
		echo "Puzzle de dimension " . $dim . " solvable : ";
		if ($output[$i] == "SOLVABLE")
		{
			echo "\033[0;32mOK\n\033[0;00m";
		}
		else
		{
			echo "\033[0;31mKO\n\033[0;00m";
		}
		++$i;
		$dim = $dim + 1;
	}
	$i = 0;
	unset($output);
	$output;
	$options = " -ui10000 ";
	$dim = 4;
	while ($i <= $loop)
	{
		exec($PATH . "/" . $gen . $options . $dim . " > test.pz");
		exec($PATH . "/" . $prog . " test.pz", $output);
		echo "Puzzle de dimension " . $dim . " unsolvable : ";
		if ($output[$i] == "UNSOLVABLE")
		{
			echo "\033[0;32mOK\n\033[0;00m";
		}
		else
			echo "\033[0;31mKO\n\033[0;00m";
		++$i;
		$dim = $dim + 1;
	}

	unset($output);
	$i = 0;
	$PATH_PUZZLE_MAPS = "./PuzzleMaps/";
	$files = scandir($PATH_PUZZLE_MAPS);
	foreach ($files as $key => $file)
	{
		exec($PATH . "/" . $prog . " " . $PATH_PUZZLE_MAPS . $file, $output);
		echo  "$file : ";
		if ($output[$key * 2] == "PARSING EXCEPTION")
		{
			echo "\033[0;32mOK\n\033[0;00m";
		}
		else
			echo "\033[0;31mKO\n\033[0;00m";
	}
