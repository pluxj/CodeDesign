package SimpleFactory

import "fmt"

// 外部不需要访问
type circle struct {
	x int
}

func (c *circle) Draw() {
	c.x = 10
	fmt.Println("circle drawing...", c.x)
}
