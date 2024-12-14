# CI/CD Exercise with Circular Buffer

This repository demonstrates a CI/CD pipeline implementation for a circular buffer program written in C++.

## Features
- Circular buffer implementation in C++
- Unit testing with Google Test
- Dockerized build and test environment
- CI/CD pipeline using GitHub Actions

## Prerequisites
- Docker installed on your machine (for local testing)
- Git (for version control)

## Getting Started

### Clone the Repository
```bash
git clone https://github.com/SubWorkGit/CICD_exercise_1.git
cd CICD_exercise_1
```

### Build and Test Locally
1. Build the Docker image:
   ```bash
   docker build -t cicd_exercise_image .
   ```
2. Run the tests inside the Docker container:
   ```bash
   docker run --rm cicd_exercise_image
   ```

## CI/CD Pipeline
The CI/CD pipeline is configured using GitHub Actions. It automates the following steps:
1. Build the Docker image.
2. Run the tests inside the Docker container.

### Triggering the Pipeline
The pipeline runs automatically:
- On every push to the `main` branch.
- On every pull request to the `main` branch.

## File Structure
```plaintext
.
├── Dockerfile            # Docker configuration for building and testing
├── src/                  # Source code of the circular buffer
├── tests/                # Unit tests for the circular buffer
├── .github/workflows/    # GitHub Actions workflows
│   └── ci.yml            # CI/CD pipeline configuration
└── README.md             # Project documentation
```

## Technologies Used
- **C++**: Core programming language
- **Google Test**: Unit testing framework
- **Docker**: Containerized build and test environment
- **GitHub Actions**: CI/CD pipeline

## License
This project is open-source and available under the [MIT License](LICENSE).

