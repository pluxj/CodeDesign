package SimpleFactory

import "fmt"

type square struct {
}

func (s square) Draw() {
	fmt.Println("square draw...")
}