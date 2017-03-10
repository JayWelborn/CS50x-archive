#!/usr/bin/env php
<?php

    // CS50 Library
    require("vendor/library50-php-5/CS50/CS50.php");
    CS50::init(__DIR__ . "/config.json");

    // ensure proper number of command line arguments
    if (count($argv) !== 2)
    {
        print("Usage: ./import.php path/to/FILE.txt\n");
        exit();
    }
    
    // ensure second argument is to a file that exists and is readable
    else if (file_exists($argv[1]) === false || is_readable($argv[1]) === false)
    {
        print("File does not exist or is not readable.\n");
        exit();
    }
    
    // ensure file is a .txt file
    else if (substr($argv[1], -4) != ".txt")
    {
        print("Must be a .txt file.\n");
        exit();
    }
    
    // read from file and write to SQL database
    else
    {
        // store filename and open file to read
        $filename = $argv[1];
        $stream = fopen($filename, "r");
        
        if($stream)
        {
            // read file line by line and query database
            while(!feof($stream))
            {
                // each line of file becomes an array
                $line = fgetcsv($stream, 0, "\t");
                
                // place each element of the array into database
                CS50::query("INSERT INTO places (country_code, postal_code, place_name, admin_name1,
                                                 admin_code1, admin_name2, admin_code2, admin_name3,
                                                 admin_code3, latitude, longitude, accuracy)
                                        VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)",
                                                $line[0], $line[1], $line[2], $line[3], $line[4], 
                                                $line[5], $line[6], $line[7], $line[8], $line[9],
                                                $line[10], $line[11]);
            }
        }
        else
        {
            print("Error Opening File\n");
        }
        fclose($stream);
    }
?>