#!/bin/bash

# Color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
MAGENTA='\033[0;35m'
CYAN='\033[0;36m'
WHITE='\033[0;37m'
RESET='\033[0m'
BOLD='\033[1m'
UNDERLINE='\033[4m'

# Path to your Cub3d executable
CUB3D_EXEC="./cub3d"

# Directory containing test maps
MAP_DIR="test_maps"
VALID_MAPS="valid_maps"
INVALID_MAPS="invalid_maps"

# Counter variables
total_tests=0
passed_tests=0

echo -e "${BOLD}${UNDERLINE}${PINK}Cub3D Map tester\n${RESET}"

echo -e "${BOLD}${PINK}Valid Maps:\n${RESET}"

# Iterate over each valid map file in the directory
for map in "$MAP_DIR"/"$VALID_MAPS"/*.cub; do
    echo "Testing map: $map"
    $CUB3D_EXEC "$map" > /dev/null 2>&1
    if [ $? -ne 0 ]; then
        echo -e "${RED}Error on map: $map${RESET}"
    else
        echo -e "${GREEN}\033[0;32mMap correct: $map${RESET}"
        ((passed_tests++))
    fi
    echo -e "\n"
    ((total_tests++))
done

echo -e "${BOLD}${PINK}\nInvalid Maps:\n${RESET}"

# Iterate over each map file in the directory
for map in "$MAP_DIR"/"$INVALID_MAPS"/*.cub; do
    echo "Testing map: $map"
    $CUB3D_EXEC "$map" > /dev/null 2>&1
    if [ $? -ne 0 ]; then
        echo -e "${GREEN}\033[0;32mMap correctly invalid: $map${RESET}"
        ((passed_tests++))
    else
        echo -e "${RED}\033[0;31mInvalid map was validated: $map${RESET}"
    fi
    echo -e "\n"
    ((total_tests++))
done

echo -e "${BOLD}${UNDERLINE}${PINK}Passed Tests: $passed_tests/$total_tests\n${RESET}"
