<table class="table table-striped">
    <thead>
        <tr>
            <th>Transaction</th>
            <th>Date/Time</th>
            <th>Symbol</th>
            <th>Shares</th>
            <th>Price</th>
        </tr>
    </thead>
    <tbody>
        <?php foreach($records as $record): ?>
        <tr>
            <td><?= $record["transaction"] ?></td>
            <td><?= date('d.m.Y H:i', strtotime($record["time"])) ?></td>
            <td><?= $record["symbol"] ?></td>
            <td><?= $record["shares"] ?></td>
            <td>$<?= $record["price"] ?></td>
        </tr>
        <?php endforeach ?>
    </tbody>
</table>