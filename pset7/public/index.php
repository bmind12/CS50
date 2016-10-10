<?php

    // configuration
    require("../includes/config.php"); 

    // render portfolio
    $positions = [];
    $rows = CS50::query("SELECT * FROM portfolios WHERE user_id = ?", $_SESSION["id"]);
    
    foreach ($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        if ($stock !== false)
        {
            $positions[] = [
                "name" => $stock["name"],
                "price" => number_format($stock["price"], 2, '.', ','),
                "shares" => $row["shares"],
                "symbol" => $row["symbol"],
                "total" => number_format($row["shares"] * $stock["price"], 2, '.', ',')
            ];
        }
    }
    
    $rows = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
    foreach ($rows as $row)
    {
        $balance = number_format($row["cash"], 2, '.', ',');
    }

    render("portfolio.php", ["positions" => $positions, "title" => "Portfolio", "balance" => $balance]);
    
?>