# IDS Final Homework

## P1 文件

### Data

| 文件名          | 文件内容                              |
| --------------- | ------------------------------------- |
| 360Dga.txt      | 360提供的DGA域名数据集                |
| dga.txt         | 由360Dga.txt格式化后的数据集          |
| top-1m.txt      | Alexa 1M 排名数据集                   |
| notdga.txt      | 由top-1m.txt格式化后的数据集          |
| bigtrain.txt    | 将dga.txt与notdga.txt结合得到的训练集 |
| test.txt        | 从bigtrain.txt中随机得到的测试集      |
| train.txt       | hwk5中的训练集                        |
| teachertest.txt | hwk5中的测试集                        |

### Result

| 文件名      | 文件内容                          |
| ----------- | --------------------------------- |
| assess.py   | 对结果文件进行准确度评价          |
| result1.txt | 第一次测试结果                    |
| result2.txt | 第二次测试结果                    |
| result3.txt | 第三次测试结果                    |
| result4.txt | 第四次测试结果                    |
| result5.txt | 第五次测试结果                    |
| sum.txt     | assess.py的输出文件，得到结果对比 |

### Script

| 文件名         | 文件内容                                  |
| -------------- | ----------------------------------------- |
| classify.py    | 训练及分类主文件                          |
| classify.py.cp | 主文件备份                                |
| getDga.py      | 由360Dga.txt格式化得到dga.txt             |
| getNotDga.py   | 由top-1m.txt格式化得到notdga.txt          |
| merge.py       | 将dga.txt与notdga.txt拼接得到bigtrain.txt |
| shuffle.py     | 由bigtrain.txt产生随机测试集test.txt      |
| test.py        | hwk5中的分类文件                          |
| result.txt     | 得到的分类结果                            |

## P2 分类主文件——classify.py

### 依赖

```python
from sklearn.ensemble import RandomForestClassifier
import numpy as np
```

### 函数及数据结构

```python
domainlist = []		# 训练集产生的域名列表
testdmlist = []		# 测试集产生的域名列表
testlist = []		# 测试集产生的特征列表

class Domain		# 域名类
	self.name		# 域名的全名
    self.label		# 域名的dga或notdga属性
  	returnData()	# 返回元音比例，总长度，数字个数，其他字符个数
    returnLabel()	# 返回域名的dga或notdga属性
    
def initData(filename)	# 读入训练集，将域名与dga属性匹配
def readTest(filename)	# 读入测试集，得到每个域名的元音比例，总长度，数字个数，其他字符个数
def main()				# 在对训练集学习后对测试集进行判断，将结果输出至result.txt文件中
```

### 输入输出文件格式

```python
# 输入训练集格式
google.com,notdga
youtube.com,notdga
tmall.com,notdga
qq.com,notdga
baidu.com,notdga
……
jlou6v164hl99vxyzmqv3neky.com,dga
1vlz03ssmneu61299h2owbfo6u.biz,dga
1qriet41nw4y641zd6ru1c9do1f.biz,dga
rxhdw0ss7upri0lg1d1ab6sg7.biz,dga
1h18y3e5jfhw91sqw9b51384eso.org,dga
……
```

```python
# 输入测试集格式
google.dz
spanishdict.com
dbs.com.sg
edx.org
forbes.com
……
1nw3r8wyqnd819zmnnd9pohle.biz
1cta31j13co7yhmflw7n18yqhvu.com
1sso8pi6i794r1t7wbgx1ie0a6n.net
1c4qba21w8mj8n1gfjinib2cme4.org
1jmymth1ctju8u34e45y1a6g27v.com
……
```

```python
# 输出结果格式
google.dz,notdga
spanishdict.com,dga
dbs.com.sg,notdga
edx.org,notdga
forbes.com,notdga
……
1nw3r8wyqnd819zmnnd9pohle.biz,dga
1cta31j13co7yhmflw7n18yqhvu.com,dga
1sso8pi6i794r1t7wbgx1ie0a6n.net,dga
1c4qba21w8mj8n1gfjinib2cme4.org,dga
1jmymth1ctju8u34e45y1a6g27v.com,dga
……
```

## P3 方法说明

+ **分类算法的设计方法**

  将360的DGA数据集与Alexa 1M的数据集作为训练集，利用随机森林算法，将域名的长度，元音字母占比，数字个数，其他字符数作为分类依据，训练得到分类器，读入测试集后将其分类，输出至result.txt文件，最终将多次分类结果进行对比，评价分类器的分类效果。

+ **测度算法选择依据**

  在观察DGA域名与普通域名的特点后得出二者的主要差异在以下几个方面：

  1. DGA域名通常较长，普通域名通常较短——选取长度
  2. DGA域名数字较多出现，普通域名通常很少包含数字——选取数字
  3. DGA域名中几乎没有正常拼写的单词，普通域名通常含有正规单词或拼音——选取元音字母占比
  4. DGA域名中有时包含其他字符，普通域名很少包含其他字符——选取其他字符个数

+ **计算方法**

  将各元素进行统计，并写入其特征元素的list中

+ **训练数据和测试数据的选择方法**

  + 训练数据

    将360的DGA数据集与Alexa 1M的数据集作为训练集

  + 测试数据
    + 训练集中随机选择五分之一的数据作为测试集
    + hwk5中的测试集

## P4 分类结果及数据分析

分类结果分为随机测试集的结果及hwk5测试集的结果

+ **随机测试集**

  ```python
  ./result1.txt:			# 域名长度+元音占比
  correctNotdga = 106034
  wrongNotdga = 23160
  correctDga = 182343
  wrongDga = 20414
  
  ./result2.txt:			# 域名长度+元音占比+数字个数
  correctNotdga = 108181
  wrongNotdga = 21013
  correctDga = 186688
  wrongDga = 16069
  
  ./result3.txt:			# 域名长度+元音占比+数字个数+其他字符数
  correctNotdga = 108528
  wrongNotdga = 20666
  correctDga = 187189
  wrongDga = 15568
  ```

  **结论：**

  	1. 域名长度与元音字母占比可以将大部分的域名成功进行分类
   	2. 数字个数与其它字符数都能进一步对某些域名进行更加精准的分类
   	3. 依据数字个数的分类效果比依据其它字符数的分类效果更优

 + **Hwk5测试集**

   ```python
   ./result4.txt:			# 域名长度+元音占比+数字个数+其他字符数
   correctNotdga = 93
   wrongNotdga = 7
   correctDga = 96
   wrongDga = 3
   
   ./result5.txt:			# 域名长度+元音占比+其他字符数
   correctNotdga = 91
   wrongNotdga = 9
   correctDga = 96
   wrongDga = 3
   
   ./result6.txt:			# 域名长度+元音占比
   correctNotdga = 91
   wrongNotdga = 9
   correctDga = 96
   wrongDga = 3
   ```

   **结论：**

   	1. Hwk5测试集的大部分DGA域名都可被成功检测
    	2. 数字个数对于此测试集有分类效果
    	3. 其他字符数对于此测试集没有分类效果
    	4. 在Hwk5中由Hwk5训练集得到的测试结果是全部正确的，而训练集并不大，因此在Hwk5中可能存在过拟合的问题

## P5 总结

因为更大的训练集包含了更多的DGA情况，有的DGA域名也并不长，元音比例也很高，数字也不多，与此同时，普通域名中也存在长域名，没有元音等情况扰乱分类器的分类依据，所以分类器会在分类时考虑更多的因素来判断域名的DGA属性，分类的正确性有待提高，可以考虑添加更多判断的元素以得到更准确的判断效果。同时观察到了过拟合可能造成的一叶障目的问题，在今后的学习中要多多注意。