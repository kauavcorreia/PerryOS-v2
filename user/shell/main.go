package main

import (
	"bufio"
	"fmt"
	"os"
	"os/exec"
	"strings"
)

func main() {

	reader := bufio.NewReader(os.Stdin)

	fmt.Println("PerryOS Shell v0.1")

	for {

		fmt.Print("perryos> ")

		input, _ := reader.ReadString('\n')
		input = strings.TrimSpace(input)

		if input == "" {
			continue
		}

		args := strings.Fields(input)

		// Comandos internos

		switch args[0] {

		case "exit":
			fmt.Println("Bye!")
			return

		case "help":
			fmt.Println("Commands:")
			fmt.Println(" help")
			fmt.Println(" exit")
			fmt.Println(" cd <dir>")
			fmt.Println(" pwd")
			fmt.Println(" clear")
			fmt.Println(" filemanager")
			continue

		case "cd":
			if len(args) > 1 {
				err := os.Chdir(args[1])
				if err != nil {
					fmt.Println("Directory not found")
				}
			}
			continue

		case "pwd":
			dir, _ := os.Getwd()
			fmt.Println(dir)
			continue

		case "clear":
			fmt.Print("\033[H\033[2J")
			continue
		}

		// Executa programa 

		cmd := exec.Command(args[0], args[1:]...)
		cmd.Stdout = os.Stdout
		cmd.Stderr = os.Stderr

		err := cmd.Run()

		if err != nil {

			// tenta executar dentro do user/
			path := "../" + args[0] + "/" + args[0]

			cmd = exec.Command(path, args[1:]...)
			cmd.Stdout = os.Stdout
			cmd.Stderr = os.Stderr

			err = cmd.Run()

			if err != nil {
				fmt.Println("Command not found")
			}
		}
	}
}