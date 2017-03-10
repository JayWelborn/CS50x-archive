<form action="buy.php" method="post">
    <fieldset>
        <div class="form-group">
            <input autocomplete="off" autofocus class="form-control" name="stock" placeholder="Stock Symbool" type="text"/>
        </div>
        <div class="form-group">
            <input autocomplete="off" autofocus class="form-control" name="shares" placeholder="Number of Shares to Buy" type="int"/>
        </div>
        <div class="form-group">
            <button class="btn btn-default" type="submit">
                <span aria-hidden="true" class="glyphicon glyphicon-log-in"></span>
                Buy
            </button>
        </div>
    </fieldset>
</form>
<div>
    or <a href="logout.php">Log Out</a> of your account.
</div>