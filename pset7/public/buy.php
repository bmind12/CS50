<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("buy_form.php", ["title" => "Buy"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $stock = lookup($_POST["symbol"]);
        $shares = $_POST["shares"];
        
        if ($_POST["symbol"] == "")
        {
            apologize("You must specify a stock to buy.");
        }
        elseif ($stock === false)
        {
            apologize("Symbol is not valid.");
        }
        elseif ($shares == "")
        {
            apologize("You must specify a number of shares.");
        }
        elseif (preg_match("/^\d+$/", $_POST["shares"]) == false || is_int($_POST["shares"] == false))
        {
            apologize("Invalid number of shares.");
        }
        
        $cost = $stock["price"] * $shares;
            
        $rows = CS50::query("SELECT * FROM users WHERE id = ?", $_SESSION["id"]);
        foreach ($rows as $row)
        {
            $cash = $row["cash"];
        }
        
        if ($cash < $cost)
        {
            apologize("You can't afford that.");
        }
        else
        {
            CS50::query("INSERT INTO portfolios (user_id, symbol, shares) VALUES (?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + ?", $_SESSION["id"], $stock["symbol"], $shares, $shares);
            CS50::query("UPDATE users SET cash = cash - ? WHERE id = ?", $cost, $_SESSION["id"]);
            CS50::query("INSERT INTO history (user_id, transaction, time, symbol, shares, price) VALUES (?, 'BUY', CURRENT_TIMESTAMP, ?, ?, ?)", $_SESSION["id"], $stock["symbol"], $shares, $stock["price"]);

            redirect("/");
        }
    }
?>