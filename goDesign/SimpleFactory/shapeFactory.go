package SimpleFactory

// 图形工厂
type ShapeFactory struct {
}

func Create(m int) Shape {
	switch m {
	case 1:
		return new(circle)
	default:
		return nil
	}
}

func (sf ShapeFactory) CreateCirle() Shape {
	return new(circle)
}

func (sf ShapeFactory) CreateSquare() Shape {
	return new(square)
}