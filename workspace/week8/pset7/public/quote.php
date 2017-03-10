<?php

    // configuration
    require("../includes/config.php");
    
    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // render form
        render("quote_form.php", ["title" => "Quote"]);
    }
    
    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["stock"]))
        {
            apologize("You must provide a stock symbol.");
        }
       
       // lookup stock current stock price
       // set local variables
       $stock = strtoupper($_POST["stock"]);
       $stock = lookup($stock);
       
       // return error if stock symbol invalid
       if ($stock === false)
       {
           apologize("Stock Symbol Invalid");
       }
       else
       {
            $symbol = $stock["symbol"];
            $name = $stock["name"];
            $price = round($stock["price"], 2);
            
           render("quote_return.php", ["title" => "Quote", "symbol" => $symbol, "name" => $name, "price" => $price]);
       }
    }
    
?>