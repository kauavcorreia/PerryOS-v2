package main

import (
	"fmt"
	"os"
)

func main() {

	dir := "."

	if len(os.Args) > 1 {
		dir = os.Args[1]
	}

	files, err := os.ReadDir(dir)

	if err != nil {
		fmt.Println("Error:", err)
		return
	}

	fmt.Println("Directory:", dir)
	fmt.Println("----------------")

	for _, file := range files {

		info, _ := file.Info()

		if file.IsDir() {
			fmt.Println("[DIR] ", file.Name())
		} else {
			fmt.Printf("[FILE] %s (%d bytes)\n", file.Name(), info.Size())
		}

	}
}