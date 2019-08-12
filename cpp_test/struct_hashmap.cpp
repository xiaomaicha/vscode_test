//
// Created by wuqi on 19-8-12.
//

#include <unordered_map>
#include <vector>
#include <bitset>
#include <string>
#include <utility>

struct Key {
  std::string first;
  std::string second;
};

struct KeyHash {
  std::size_t operator()(const Key& k) const
  {
    return std::hash<std::string>()(k.first) ^
        (std::hash<std::string>()(k.second) << 1);
  }
};

struct KeyEqual {
  bool operator()(const Key& lhs, const Key& rhs) const
  {
    return lhs.first == rhs.first && lhs.second == rhs.second;
  }
};

struct Foo {
  Foo(int val_) : val(val_) {}
  int val;
  bool operator==(const Foo &rhs) const { return val == rhs.val; }
};

namespace std {
template<> struct hash<Foo> {
  std::size_t operator()(const Foo &f) const {
    return std::hash<int>{}(f.val);
  }
};
}

int main()
{
  // 默认构造函数：空 unordered_map
  std::unordered_map<std::string, std::string> m1;

  // 列表构造函数
  std::unordered_map<int, std::string> m2 =
      {
          {1, "foo"},
          {3, "bar"},
          {2, "baz"},
      };

  // 复制构造函数
  std::unordered_map<int, std::string> m3 = m2;

  // 移动构造函数
  std::unordered_map<int, std::string> m4 = std::move(m2);

  // 范围构造函数
  std::vector<std::pair<std::bitset<8>, int>> v = { {0x12, 1}, {0x01,-1} };
  std::unordered_map<std::bitset<8>, double> m5(v.begin(), v.end());

  // 带定制 Key 类型的构造函数的选项 1
  // 定义 KeyHash 与 KeyEqual 结构体并在模板中使用它们
  std::unordered_map<Key, std::string, KeyHash, KeyEqual> m6 = {
      { {"John", "Doe"}, "example"},
      { {"Mary", "Sue"}, "another"}
  };

  // 带定制 Key 类型的构造函数的选项 2
  // 为 class/struct 定义 const == 运算符并于 std 命名空间特化 std::hash 结构体
  std::unordered_map<Foo, std::string> m7 = {
      { Foo(1), "One"}, { 2, "Two"}, { 3, "Three"}
  };

  // 选项 3 ：用 lambdas
  // 注意必须将初始桶数传递给构造函数
  struct Goo {int val; };
  auto hash = [](const Goo &g){ return std::hash<int>{}(g.val); };
  auto comp = [](const Goo &l, const Goo &r){ return l.val == r.val; };
  std::unordered_map<Goo, double, decltype(hash), decltype(comp)> m8(10, hash, comp);
}
