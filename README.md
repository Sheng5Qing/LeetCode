# LeetCode
**刷题记录**
>//同步测试 github ---> gitee
---
## 1.两数之和
使用哈希表记录与遍历数组下标,每遍历到一个数字，就去查看哈希表中是否存在`target-num[i]`的值，若存在，则说明已存在两数之和为`target`，直接返回即可。否则，将当前数字与其下标存储到哈希表中，继续遍历。
时间复杂度为O(n)。
### unordered_map容器用法详解
unordered_map 容器，直译过来就是"无序 map 容器"的意思。所谓“无序”，指的是 unordered_map 容器不会像 map 容器那样对存储的数据进行排序。
若想要使用该容器，需要包含`<unordered_map>`，即：
```c++
include <unordered_map>
```
#### 创建unordered_map容器的方法
1.  通过调用 unordered_map 模板类的默认构造函数，可以创建空的 unordered_map 容器。如：
```c++
std::unordered_map<std::string, std::string> umap;
```
2. 在创建 unordered_map 容器的同时，可以完成初始化操作。
```c++
//容器中存储的各个键值对的键是不能相等的
std::unordered_map<std::string, std::string> umap{
    {"1", "Hello"},
    {"2", "World"},
    {"3", "Hello"},
    {"4", "unordered_map"}
};
```
3. 另外，还可以调用 unordered_map 模板中提供的复制（拷贝）构造函数，将现有 unordered_map 容器中存储的键值对，复制给新建 unordered_map 容器。
```c++
std::unordered_map<std::string, std::string> umap2(umap);
```
4. 当然，如果不想全部拷贝，可以使用 unordered_map 类模板提供的迭代器，在现有 unordered_map 容器中选择部分区域内的键值对，为新建 unordered_map 容器初始化。例如：
```c++
//迭代器从第二个元素到最后一个元素
std::unordered_map<std::string, std::string> umap2(++umap.begin(),umap.end());
//从第三个元素开始
std::unordered_map<std::string, std::string> umap2(std::next(umap.begin(), 2), umap.end());
```
#### 成员方法
成员方法|功能
:-----|:---|
begin()|返回指向容器中第一个键值对的正向迭代器
end() |返回指向容器中最后一个键值对**之后位置**的正向迭代器。
cbegin()|和 begin() 功能相同，只不过在其基础上增加了 const 属性，即该方法返回的迭代器不能用于修改容器内存储的键值对。
cend()|和 end() 功能相同，只不过在其基础上，增加了 const 属性，即该方法返回的迭代器不能用于修改容器内存储的键值对。
empty()|若容器为空，则返回 true；否则 false
size()|返回当前容器中存有键值对的个数。
max_size()|返回容器所能容纳键值对的最大个数，不同的操作系统，其返回值亦不相同。
operator[key]|	该模板类中重载了 [] 运算符，其功能是可以向访问数组中元素那样，只要给定某个键值对的键 key，就可以获取该键对应的值。如果当前容器中没有以 key 为键的键值对，则其会使用该键向当前容器中插入一个新键值对。<br>`umap[1]`
at(key)|返回容器中存储的键 key 对应的值，如果 key 不存在，则会抛出 out_of_range 异常。 
find(key)|查找以 key 为键的键值对，如果找到，则返回一个指向该键值对的正向迭代器；反之，则返回一个指向容器中最后一个键值对之后位置的迭代器（end() 方法返回的迭代器）。
count(key)|在容器中查找以 key 键的键值对的个数。
equal_range(key)|返回一个 pair 对象，其包含 2 个迭代器，用于表明当前容器中键为 key 的键值对所在的范围。
emplace()|向容器中添加新键值对，直接在容器中构造元素，而不需要先创建元素然后复制或移动到容器中，效率比 insert() 方法高。<br>`umap.emplace(1, "one"); `
emplace_init()|向容器中添加新键值对，效率比 insert() 方法高。<br>`auto hint = umap.begin();`<br>`umap.emplace_hint(hint, 1, "one");  // 提示新元素应该插入在umap的开始`
insert()|向容器中添加新键值对。<br>`std::pair<int, std::string> element(1, "one");`<br>`umap.insert(element);  // 插入已经构造好的元素`<br>或者<br>`umap.insert(make_pair(1,"one"));`
erase()|删除指定键值对。
clear()|清空容器，即删除容器中存储的所有键值对。
swap()|交换 2 个 unordered_map 容器存储的键值对，前提是必须保证这 2 个容器的类型完全相等。
bucket_count()|返回当前容器底层存储键值对时，使用桶（一个线性链表代表一个桶）的数量。
max_bucket_count()|返回当前系统中，unordered_map 容器底层最多可以使用多少桶。
bucket_size(n)|	返回第 n 个桶中存储键值对的数量。
bucket(key)|返回以 key 为键的键值对所在桶的编号。
load_factor()|返回 unordered_map 容器中当前的负载因子。负载因子，指的是的当前容器中存储键值对的数量（size()）和使用桶数（bucket_count()）的比值，即 `load_factor() = size() / bucket_count()。`
max_load_factor()|返回或者设置当前 unordered_map 容器的负载因子。
rehash()|将当前容器底层使用桶的数量设置为 n。
reserve()|将存储桶的数量（也就是 bucket_count() 方法的返回值）设置为至少容纳count个元（不超过最大负载因子）所需的数量，并重新整理容器。
hash_function()|返回当前容器使用的哈希函数对象。