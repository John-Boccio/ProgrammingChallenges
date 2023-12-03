import Foundation

public struct Day1 {
    public static func solve(inputDir: URL) -> Int? {
        let filePath = inputDir.appendingPathComponent("day1_input.txt")

        guard let content = try? String(contentsOfFile: filePath.absoluteString, encoding: .utf8) else {
            print("Couldn't find file at \(filePath)")
            return nil
        }
        var totalSum: Int = 0
        content.enumerateLines { line, _ in
            var firstChar: Character?
            var lastChar: Character?

            for char in line {
                if char.isNumber {
                    if firstChar == nil {
                        firstChar = char
                    }
                    lastChar = char
                }
            }
            totalSum += Int(String(firstChar!) + String(lastChar!))!
        }

        return totalSum
    }
}
