import Foundation


@main
public struct AoC {
    public private(set) var text = "Hello, World!"

    public static func main() {
        guard let inputsDir = URL(string: "input") else {
            print("Failed to create the URL at \"input\"")
            return
        }

        let result = Day1.solve(inputDir: inputsDir)
        if let result {
            print("Solution: \(result)")
        } else {
            print("Failed to find solution")
        }
    }
}
