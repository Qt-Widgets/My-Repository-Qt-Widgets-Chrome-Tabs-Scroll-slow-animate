平滑滚动列表框
===

普普通通的平滑滚动，通过 `QTimer` 做到平滑效果。

为什么不使用 ` setVerticalScrollMode(QAbstractItemView::ScrollPerPixel)` ？

只是从一瞬间滚动一个item，变成了一瞬间滚动x像素，视觉效果并无变化，也不是平滑滚动。

---

有另一种通过 `QPropertyAnimation` 的实现，效果也不错，可自行网上搜索。

为什么选择 `QTimer`？

——**细节上可控**，精确到像素级别的掌控。

| 交互     | QTimer                                                       | QPropertyAnimation                 |
| -------- | ------------------------------------------------------------ | ---------------------------------- |
| 滚动叠加 | 当滚轮快速连续滚动时，效果可重复叠加，就是滚轮滑动越快，**界面滚动越快** | 仅读取最后一次都滚动，前面都会放弃 |
| 动画效果 | 在不叠加的基础上，是匀速的                                   | 支持**非线性动画**                 |
| 中止滚动 | 当正在快速滑到底途中又突然上滑，会发生什么？——下滑效果完全消失，不影响用户操作 | 仅最后一次滚动效果                 |
| 性能开销 | 创建多个滚动对象，占用更多CPU                                | 只一个动画对象，开销极低           |
| 重绘次数 | 当delegate十分复杂的时候……还是放弃吧                         | 都可以                             |

