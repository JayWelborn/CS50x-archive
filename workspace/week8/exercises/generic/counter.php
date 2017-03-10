<?php

    session_start();
    if(isset($_SESSION["counter"]))
    {
        $counter = $_SESSION["counter"];
    }
    else
    {
        $counter = 0;
    }
    
    $_SESSION["counter"] = $counter + 1
?>