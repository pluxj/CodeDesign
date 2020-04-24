package singleton

import "sync"

type singleton struct {
}

var mu sync.Mutex
var instance *singleton
func GetInstance() *singleton {
	if instance == nil {
		mu.Lock()
		if instance == nil {
			instance = new(singleton)
		}
		mu.Unlock()
	}
	return instance
}

var once sync.Once
var instance2 *singleton
func GetInstance2() *singleton {
	once.Do(func() {
		instance2 = &singleton{}
	})
	return instance2
}
