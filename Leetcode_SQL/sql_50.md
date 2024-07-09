### 1193. Monthly Transactions I
``` mysql
SELECT SUBSTR(trans_date,1,7) AS month,
        country,
        COUNT(id) AS trans_count,
        SUM(IF(state = "approved",1 ,0)) AS approved_count,
        SUM(amount) AS trans_total_amount,
        SUM(IF(state = "approved",amount ,0)) AS approved_total_amount
FROM Transactions
GROUP BY 1, 2
```

**提取日期的年，月：**
方法1：SUBSTR(trans_date,1,7) 
方法2：left(trans_date,7)
方法3：DATE_FORMAT(trans_date, '%Y-%m')
**count 内容为approved的数量**
用SUM和IF,IF判断内容为approved，就设置为1，total amount也是如此，如果为approved就设置为amount。

### 
``` mysql
SELECT SUBSTR(trans_date,1,7) AS month,
        country,
        COUNT(id) AS trans_count,
        SUM(IF(state = "approved",1 ,0)) AS approved_count,
        SUM(amount) AS trans_total_amount,
        SUM(IF(state = "approved",amount ,0)) AS approved_total_amount
FROM Transactions
GROUP BY 1, 2
```