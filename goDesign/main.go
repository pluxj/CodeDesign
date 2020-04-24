package main

import (
	"fmt"
	"goroutinepoll/SimpleFactory"
)





func main() {

	// simple factory
	
	sf := SimpleFactory.ShapeFactory{}
	c := sf.CreateCirle()
	sq := sf.CreateSquare()
	c.Draw()
	sq.Draw()
}

