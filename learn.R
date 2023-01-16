a <- 10
A <- 11

# Data Types
mynumeric <- 19.2
mylogical <- TRUE
mycharacter <- "my little story"
myfactor <- as.factor("female")


# Vectors
vec1 <- c(1, 2, 3, 4, 0.3)
vec2 <- c(T, F, FALSE, TRUE, F)
vec3 <- c("a", "b", "b", mycharacter)
vec4 <- as.factor(c("female", "male", "male", "female"))
vec5 <- c(1, TRUE, "b")
vec6 <- c(1, TRUE, FALSE)

# List
mylist <- list(vec1, vec2, vec3, vec4, list(vec5, vec6))

# Data Frames
df <- data.frame(size = vec1, time = vec2);
plot(df)

#Matrix
mymatrix <- matrix(vec3, 2, 2)
