package com.example.webFlux.controler;

import com.example.webFlux.entity.User;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import reactor.core.publisher.Flux;
import reactor.core.publisher.Mono;

import javax.annotation.PostConstruct;
import java.util.HashMap;
import java.util.Map;
import java.util.stream.Collectors;

/**
 * @FileName: UserController
 * @author: qianBaoLi
 * @date: 2020/11/24 19:01
 * @Description: null
 */
@RestController
@RequestMapping("/user")
public class UserController {

    Map<Long, User> users = new HashMap<>();

    @PostConstruct
    public void init() throws Exception {
        users.put(Long.valueOf(1),new User(1,"liqianbao",18));
        users.put(Long.valueOf(2),new User(2,"znsfox",2));
    }

    /**
     * get all users
     * @return
     */
    @GetMapping("/list")
    public Flux<User> getAll() {
        return Flux.fromIterable(users.entrySet().stream()
                    .map(Map.Entry::getValue)
                    .collect(Collectors.toList())
        );
    }

    /**
     * get single User
      * @param id
     * @return
     */
    @GetMapping("/{id}")
    public Mono<User> getUser(@PathVariable long id) {
        return Mono.justOrEmpty(users.get(id));
    }

    @PostMapping("/add")
    public Mono<ResponseEntity<String>> addUser(User user) {
        user.setAge(32);
        user.setName("xyd");
        users.put(user.getId(),user);
        return Mono.just(new ResponseEntity<>("添加成功", HttpStatus.CREATED));
    }
}
