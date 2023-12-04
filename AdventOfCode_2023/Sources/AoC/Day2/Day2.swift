import Foundation

public struct Day2 {
    public static func solve(inputDir: URL) -> Int? {
        let filePath = inputDir.appendingPathComponent("day2_input.txt")

        guard let content = try? String(contentsOfFile: filePath.absoluteString, encoding: .utf8) else {
            print("Couldn't find file at \(filePath)")
            return nil
        }

        var cubePowerSum = 0
        content.enumerateLines { line, leave in
            let split = line.split(separator: ":")
            if split.count != 2 {
                print("Line \(line) is misformatted")
                leave = true
                return
            }

            // guard let gameID = self.parseGameID(String(split[0])) else {
            //     print("Could not parse game ID \(String(split[0]))")
            //     leave = true
            //     return
            // }

            var maxCubeCounts = [0, 0, 0]
            let gameStrings = split[1].split(separator: ";")
            for game in gameStrings {
                guard let cubes = self.parseCubesDrawn(String(game)) else {
                    leave = true
                    return
                }
    
                for (idx, cube) in cubes.enumerated() {
                    maxCubeCounts[idx] = max(cube, maxCubeCounts[idx])
                }
            }

            var newSum = 1
            for maxCubeCount in maxCubeCounts {
                newSum *= maxCubeCount
            }
            cubePowerSum += newSum
        }

        return cubePowerSum
    }

    private static func parseGameID(_ gameID: String) -> Int? {
        let gameSplit = gameID.split(separator: " ")
        if gameSplit.count != 2 {
            print("Invalid game format: \(gameID)")
            return nil
        }

        guard let game = Int(gameSplit[1]) else {
            print("Could not parse \(gameSplit[1]) into an integer")
            return nil
        }
        return game
    }

    private static func parseCubesDrawn(_ cubesDrawn: String) -> [Int]? {
        let cubes = cubesDrawn.split(separator: ",")

        var cubeCounts = [0, 0, 0]
        for cube in cubes {
            let cube = cube.trimmingCharacters(in: .whitespaces)
            let cubeCountStr = cube.split(separator: " ")
            if cubeCountStr.count != 2 {
                print("Misformatted cube: \(cubeCountStr)")
                return nil
            }

            guard let cubeCount = Int(cubeCountStr[0]) else {
                print("Could not convert \(cubeCountStr) to int")
                return nil
            }

            switch cubeCountStr[1] {
                case "red":
                    cubeCounts[0] = cubeCount
                    break
                case "green":
                    cubeCounts[1] = cubeCount
                    break
                case "blue":
                    cubeCounts[2] = cubeCount
                    break
                default:
                    print("Invalid color \(cubeCountStr[1])")
                    return nil
            }
        }

        return cubeCounts
    }
}
